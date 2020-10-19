def bubbleSort(arr, desc=False):
	sorted = False
	while (not sorted):
		sorted=True

		for i in range(len(arr)-1):
			if(not desc):
				if(arr[i] > arr[i+1]):
					sorted=False
					temp = arr[i]
					arr[i] = arr[i+1]
					arr[i+1] = temp
			else:
				if(arr[i] < arr[i+1]):
					sorted=False
					temp = arr[i]
					arr[i] = arr[i+1]
					arr[i+1] = temp
	return arr
