void	swap(int *arr, int a, int b)
{
	int	swap;

	swap = arr[a];
	arr[a] = arr[b];
	arr[b] = swap;
}

void	sort(int *arr, int start, int end)
{
	int	i;
	int	pivot;
	int	llen;
	int	hlen;

	pivot = (start + end) / 2;
	llen = 0;
	hlen = 0;
	i = start;
	if (end <= start)
		return ;
	if (end == start + 1 && arr[start] > arr[end])
	{
		swap(arr, end, start);
		return ;
	}
	while (i <= end)
	{
		if (arr[i] < arr[pivot])
			swap(arr, i, start + llen++);
		else if (arr[i] > arr[pivot])
			swap(arr, i, end - hlen++);
		else if (i != pivot)
			return ;
		i++;
	}
	sort(arr, 0, pivot - 1);
	sort(arr, pivot + 1, end);
}

int	main(void)
{
	int	i = 0;
	int	arr[] = {1, 4, 5, 3, 2, 6};

	sort(arr, 0, 6);
	while (i < 6)
		printf("%d ", arr[i++]);
}