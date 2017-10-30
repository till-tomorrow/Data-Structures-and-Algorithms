public void StartSorting()
{
        int[] arr = { 800, 11, 50, 771, 649, 770, 240, 9 }; //could be customized

        int temp = 0;

        for (int write = 0; write < arr.Length - 1; write++) {
            for (int sort = 0; sort < arr.Length - write - 1; sort++) {
                if (arr[sort] > arr[sort + 1]) {
                    temp = arr[sort + 1];
                    arr[sort + 1] = arr[sort];
                    arr[sort] = temp;
                }
            }
        }

        for (int i = 0; i < arr.Length; i++)
            Console.Write(arr[i] + " ");

Console.ReadKey();

}
