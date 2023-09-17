import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class test{
  static List<Integer> sortArray(List<Integer> arr){
    Collections.sort(arr);
    return arr;
  }
  public static void main(String[] args) throws Exception{
    FileReader fr = new FileReader("testcases.txt");
    Scanner sc = new Scanner(fr);
    while(sc.hasNextLine()){
      String line = sc.nextLine();
      String[] arr = line.split("#");
      String[] input = arr[0].split(" ");
      String[] output = arr[1].split(" ");
      List<Integer> inputList = new ArrayList<>();
      List<Integer> outputList = new ArrayList<>();
      for(String i: input){
        inputList.add(Integer.parseInt(i));
      }
      for(String i: output){
        outputList.add(Integer.parseInt(i));
      }
      System.out.println(inputList+" "+outputList);
      List<Integer> result = sortArray(inputList);
      assert result.equals(outputList);
    }
    sc.close();

  }
}
