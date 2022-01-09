import java.util.Scanner;
import java.util.Random;
import java.math.BigInteger;

public class Main 
{
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		//Matrisin elemanlar�n� tek ve �ift dizi olarak d�nd�rme
		int[][] matrice = new int[][] {
			{56,23,678,231},
			{234,21,78,26},
			{654,33,32,67},
			{189,35,56,89}
		};
		
		printMatrice(matrice, "Matrisin g�r�nt�s�: \n");
		System.out.println();
		
		int[] a = oddArr(matrice);
		int[] b = evenArr(matrice);
		
		printArray(a, "Tek say�lardan olu�an dizi: ");
		printArray(b, "�ift say�lardan olu�an dizi: ");
		
		//matrisin en b�y�k eleman�n� bulma
		int c = fMax(matrice);
		System.out.printf("\nBu matrisin en b�y�k eleman�: %d \n", c);
		
		//Matriste arama
		System.out.printf("\nAramak istedi�iniz say�y� girin: ");
		int input = in.nextInt();
		System.out.println(matriceSearch(input, matrice));
	}
	
	//Tek mi �ift mi d�nd�ren fonksiyon
	public static boolean isOdd(double a)
	{
		if(a % 2 != 0)
		{
			return true;
		}
		return false;
	}
	
	//oe = 1 ise gelen matrisin i�erisindeki tek say�lar�n miktar�n� oe = 2 ise �ift say�lar�n miktar�n� bulan fonksiyon
	public static int countOddEven(int oe, int[][] arr)
	{
		int count = 0;
		for(int i = 0; i < arr.length; i++)
		{
			for(int j = 0; j < arr[0].length; j++)
			{
				if(oe == 1)
				{
					if(isOdd(arr[i][j]))
					{
						count++;
					}					
				}
				else if(oe == 2)
				{
					if(!isOdd(arr[i][j]))
					{
						count++;
					}
				}
			}
		}
		
		return count;
	}
	
	//Matrisin tek elemanlar�ndan dizi olu�turmak i�in
	public static int[] oddArr(int arr[][])
	{
		int k = 0;
		int[] oddArray = new int[countOddEven(1,arr)];
		
		for(int i = 0; i < arr.length; i++)
		{
			for(int j = 0; j < arr[0].length; j++)
			{
				if(isOdd(arr[i][j]))
				{
					oddArray[k++] = arr[i][j];
				}
			}
		}
		
		return oddArray;
	}
	
	//Matrisin �ift elemanlar�ndan dizi olu�turmak i�in
	public static int[] evenArr(int arr[][])
	{
		int[] evenArray = new int[countOddEven(2,arr)];
		int k = 0;
		
		for(int i = 0; i < arr.length; i++)
		{
			for(int j = 0; j < arr[0].length; j++)
			{
				if(!isOdd(arr[i][j]))
				{
					evenArray[k++] = arr[i][j];
				}
			}
		}
		
		return evenArray;
	}
	
	//En b�y��� bulmak i�in
	public static int fMax(int arr[][])
	{
		int max = arr[0][0];
		for(int i = 0; i < arr.length; i++)
		{
			for(int j = 0; j < arr[0].length; j++)
			{
				if(arr[i][j] > max)
				{
					max = arr[i][j];
				}
			}
		}
		
		return max;
	}
	
	//Girilen say� matriste var m� diye bakan uygulama
	public static boolean matriceSearch(int key, int arr[][])
	{
		for(int i = 0; i < arr.length; i++)
		{
			for(int j = 0; j < arr[0].length; j++)
			{
				if(arr[i][j] == key)
				{
					return true;
				}
			}
		}
		
		return false;
	}
	
	//Gelen tek boyutlu diziyi ekrana yazd�ran fonksiyon
	public static void printArray(int arr[], String text)
	{
		System.out.printf(text);
		for(int i = 0; i < arr.length; i++)
		{
			System.out.printf("%d ", arr[i]);
		}
		System.out.println();
	}
	
	//Gelen matrisi ekrana yazd�ran fonksiyon
	public static void printMatrice(int arr[][], String text)
	{
		System.out.printf(text);
		for(int i = 0; i < arr.length; i++)
		{
			for(int j = 0; j < arr[0].length; j++)
			{
				System.out.printf("%d ", arr[i][j]);
			}
			System.out.println();
		}
	}

	
}