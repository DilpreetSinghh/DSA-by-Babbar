arr[6]: Int = [1, 2, 3, 8, 9, 10]

int start = 0;
int end = arr.count - 1;
int mid = start + (end - start) / 2;

func firstAndLastOccurrence(arr: [Int], key: Int) -> Int{
  while start <= end {
    if(arr[mid] == key){
      return mid
    }
    else if(arr[mid] < key){
      start = mid+1
    }
    else{
      end = mid -1
    }

  }
}  

firstOccurrence(arr, 8)