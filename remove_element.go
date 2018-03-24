package main

import (
	"fmt"
)

//将数组的指定值去掉，并返回去掉指定值后数组的长度。
//注意：只能在原来数组操作
func RemoveSpecificValue(array []int, length int, value int) int {
	if length == 0 {
		return 0
	}
	for i := 0; i < length; i++ {
		if array[i] == value {
			for j := i; j < length-1; j++ {
				array[j] = array[j+1]
			}
			length = length - 1
			i = i - 1
		}
	}
	fmt.Println(length)
	fmt.Println(array)
	return length
}

func main() {
	var array []int = []int{2, 3, 4, 5, 2, 6, 7, 2, 2, 10, 2, 2, 2, 12, 13}
	RemoveSpecificValue(array, len(array), 2)

}
