package main

import (
	"fmt"
	"sort"
)

func main() {
	var t int
	fmt.Scan(&t)
	for ; t > 0; t-- {
		var n int
		fmt.Scan(&n)
		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		sort.Ints(a)
		fmt.Println(a[n-1] + a[n-2] - a[0] - a[1])
	}
}
