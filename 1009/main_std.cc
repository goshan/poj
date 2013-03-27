#include <stdio.h>
int n, t, k;
int num[2000], sum[2000], digit[2000], ansdigit[5000], ansnum[5000];
int abs(int x)
{
if (x < 0) return -x;
return x;
}
inline int map(int c, int now)
{
switch (c)
{
    case 0: return now - t - 1;
    case 1: return now - t;
    case 2: return now - t + 1;
    case 3: return now - 1;
    case 4: return now + 1;
    case 5: return now + t - 1;
    case 6: return now + t;
    case 7: return now + t + 1;
}
}
int number(int c, int y, bool forward)
{
int i;
if (forward)
{
    for (i = c; i <= n; ++i)
      if (sum[i] >= y) break;
   return i;
}
else
{
    for (i = c; i > 0; --i)
      if (sum[i] < y) break;
    return i+1;
}
}
bool ok(int now, int i)
{
if (now < t && (i == 1 || i == 0 || i == 2)) return false;
if (now > sum[n] - t && (i == 6 || i == 5 || i == 7)) return false;
if (now % t == 1 && (i == 0 || i == 3 || i == 5)) return false;
if (now % t == 0 && (i == 2 || i == 4 || i == 7)) return false;
return true;
}
int get(int x, int now)
{
int i, max = 0, m;
for (i = 0; i < 8; ++i)
{
    m = map(i, now);
    if (ok(now, i) && m > 0 && m <= sum[n])
    {
      m = number(x, m, i / 4);
      if (max < abs(digit[x] - digit[m])) max = abs(digit[x] - digit[m]);
    }
}
return max;
}
int late(int x, int now, int r)
{
    int p;
    if (r <= now) return 1;
   if (now % t != 1)
    {
        if (digit[number(x, now - 1, 0)] != digit[x]) return 1;
        if (now > t)
        {
            p = number(x, now - t - 1, 0);
            if ((sum[p] - 1) / t < (now - 1) / t)
            {
              if (sum[p] <= now - t + 1) return 1;
              if (r > sum[p] - 1 + t) r = sum[p] - 1 + t;
            }
        }
        if (now <= sum[n] - t)
        {
            p = number(x, now + t - 1, 1);
            if ((sum[p] - 1) / t == (now - 1) / t + 1)
           {
              if (sum[p] <= now + t + 1) return 1;
              if (r > sum[p] - 1 - t) r = sum[p] - 1 - t;
            }
        }
        return r - now + 1;
    }
    else
    {
        if (now > t)
        {
            p = number(x, now - t, 0);
           if ((sum[p] - 1) / t < (now - 1) / t)
            {
              if (sum[p] <= now - t + 1) return 1;
              if (r > sum[p] - 1 + t) r = sum[p] - 1 + t;
            }
        }
        if (now <= sum[n] - t)
        {
            p = number(x, now + t, 1);
            if ((sum[p] - 1) / t == (now - 1) / t + 1)
            {
              if (sum[p] <= now + t + 1) return 1;
              if (r > sum[p] - 1 - t) r = sum[p] - 1 - t;
            }
        }
        return r - now + 1;
    }
}
void make(int x, int start, int end)
{
int i, r;
int a = (start - 1) / t, b = (end - 1) / t;
if (a != b)
{
    make(x, start, b * t);
    make(x, b * t + 1, end);
    return;
}
int last = get(x, start), sum = 0, the;
for (i = start; i <= end;)
{
    the = get(x, i);
    r = late(x, i, end - 1);
    if (the == last)
      sum += r;
    else
    {
      ansdigit[++k] = last;
      ansnum[k] = sum;
      sum = r;
      last = the;
    }
    i += r;
}
ansdigit[++k] = last;
ansnum[k] = sum;
}
int main()
{
int i, x, y;
sum[0] = 0;
while (scanf("%d", &t) && t)
{
    i = 0;
    k = 0;
    while (scanf("%d%d", &x, &y) && (x || y))
    {
      digit[++i] = x;
      num[i] = y;
      sum[i] = sum[i - 1] + num[i];
    }
    n = i;
    for (i = 1; i <= n; ++i)
    {
      if (num[i] <= t + t + 2)
        make(i, sum[i - 1] + 1, sum[i]);
      else
      {
        make(i, sum[i - 1] + 1, sum[i - 1] + t + 1);
        ansdigit[++k] = 0;
        ansnum[k] = num[i] - 2 * t - 2;
        make(i, sum[i] - t, sum[i]);
      }
    }
    printf("%d\n", t);
    for (i = 1; i <= k;)
    {
      int outdigit = ansdigit[i];
      int outnum = 0;
      while (i <= k && ansdigit[i] == outdigit)
        outnum += ansnum[i++];
      printf("%d %d\n", outdigit, outnum);
    }
    printf("0 0\n");
}
printf("0\n");
}