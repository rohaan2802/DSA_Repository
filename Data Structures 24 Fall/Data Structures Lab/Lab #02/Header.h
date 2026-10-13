#pragma once
template<typename T>
T* sumOfArrays(const T arr1[], const T arr2[], int size)
{
	T *array=new T[size];
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j <= i; j++)
		{
			array[i] = arr1[i] + arr2[j];
		}
	}
	return array;
 delete[] array;
}

template <typename T>
void rearrangeArray(T arr[], int size) 
{
    T *array=new T[size];

    int x = 0,y = size - 1;

    for (int i = 0; i < size; ++i) 
    {

        if (i%2==0)
        {
            array[i] = arr[y];
            y--;
        }
        else
        {
            array[i] = arr[x];
            x++;
        }
      
    }

    
    for (int i = 0; i < size; ++i)
    {
        arr[i] = array[i];
    }
 delete[] array;
}

template <typename T>
T findMostFrequentElement(T arr[], int size)
{
    T occurence;
    int max_count=0;

        for (int i = 0; i < size; i++) 
        {
            int count = 0;

            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }

            if (count > max_count) 
            {
                max_count = count;
                occurence = arr[i];
            }
        }

        return occurence;
    

   

}


template<typename T>
class Container
{
private:
	T* arr;
	int size;
public:
	Container(T* array, int x)
	{
		size = x;
		arr = new T[size];
			for (int i = 0; i < size; i++)
			{
				arr[i] = array[i];
			}
	}
	
		


	T* sortInWaveForm()
	{
		for (int i = 0; i < size; i +=2)
		{
			if (arr[i]<arr[i+1])
			{
				T temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = temp;
			}
		}
		return arr;
	}

	
};
