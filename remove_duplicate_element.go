package main

import (
	"fmt"
)

//删除一个排序数组中的重复元素，并返回数组的长度；
//[1,1,2,2,2,3,4] -> [1,2,3,4] length=4;
//要求不增加额外的内存空间，在原数组上完成操作；
func RemoveRepeatElem(array []int, length int) int {
	if length == 0 {
		return 0
	}
	var j int = 0
	var i int = 0
	var moveLength int = 0
	for i = 1; i < length; i++ {
		if array[i] == array[j] {
			continue
		}
		moveLength = i - j - 1
		if moveLength != 0 {
			for k := i; k < length; k++ {
				array[k-moveLength] = array[k]
			}
			length = length - moveLength
			i = i - moveLength
		}
		j++
	}
	fmt.Println(array)
	fmt.Println(i)
	return length
}

func RemoveRepeatElem1(a []int, length int) int {
	if length == 0 {
		return 0
	}
	var j int = 0
	for i := 1; i < length; i++ {
		if a[i] == a[j] {
			continue
		}
		j++
		a[j] = a[i]
	}
	j++
	fmt.Println(j)
	fmt.Println(a)
	return j

}
func main() {
	var array []int = []int{1, 2, 2, 2, 3, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10}
	var array1 []int = []int{1, 2, 2, 2, 3, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10}
	RemoveRepeatElem(array, len(array))
	RemoveRepeatElem1(array1, len(array1))
}
