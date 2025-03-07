# slower

for _ in range(int(input())):
	n, k, z = map(int, input().split())
	a = [int(x) for x in input().split()]
	ans = 0
	s = 0
	mx = 0
	for t in range(z + 1):
		pos = k - 2 * t
		if pos < 0:
			continue
		mx = 0
		s = 0
		for i in range(pos + 1):
			if i < n - 1:
				mx = max(mx, a[i] + a[i + 1])
			s += a[i]
		ans = max(ans, s + mx * t)
	print(ans)