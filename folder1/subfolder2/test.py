


def sortArray(arr):
  return sorted(arr)


def main():
  with open('testcases.txt','r') as f:
    for line in f:
      input = line.split("#")[0]
      output = line.split("#")[1]
      arr = list(map(int,input.split()))
      expected_output = list(map(int,output.split()))
      assert sortArray(arr) == expected_output
main()