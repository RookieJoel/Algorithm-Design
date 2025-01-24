package main

import "fmt"

func mod(a, n, k int64) int64 {
	if n == 1 {
		return a % k
	}
	if n%2 == 0 {
		return (mod(a, n/2, k) * mod(a, n/2, k)) % k
	} else {
		temp := mod(a, n/2, k)
		temp = (temp * temp) % k
		return (temp * (a % k)) % k
	}
}

func main() {
	var a, n, k int64
	fmt.Scan(&a, &n, &k)
	ans := mod(a, n, k)
	fmt.Println(ans)
}
