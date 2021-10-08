#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*comparator)(void* a, void* b);


static void merge(char* src, size_t start, size_t end, char* dest, size_t width, comparator cmp) {
	size_t mid = (start + end) / 2;
	size_t i = start;
	size_t j = mid;

	for(size_t k = start; k < end; ++k) {
		char * ip = &src[i * width]; // pointer to element at i
		char * jp = &src[j * width]; // pointer to element at j
		if (i < mid && (j >= end || cmp(ip, jp) < 0)) {
			memcpy(&dest[k * width], ip, width);
			i += 1;
		} else {
			memcpy(&dest[k * width], jp, width);
			j += 1;
		}
	}
}


static void split(char* src, size_t start, size_t end, char* dest, size_t width, comparator cmp) {
	if(end - start <= 1) {
		return;
	}

	size_t mid = (start + end) / 2;

	split(dest, start, mid, src, width, cmp);
	split(dest, mid, end, src, width, cmp);
	merge(src, start, end, dest, width, cmp);
}


void merge_sort(void* array, size_t array_size, size_t width, comparator cmp) {
	char* src = (char*) array;
	char* copy = malloc(array_size * width);
	memcpy(copy, src, array_size * width); 

	split(copy, 0, array_size, src, width, cmp);

	free(copy);
}
