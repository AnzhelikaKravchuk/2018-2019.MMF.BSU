<Query Kind="Program" />

void Main()
{
	int[] array = new int[] { 1, 3, 5, 6, 8, 6, 0 };
	int[] result = ArrayExtention.Filter(array, new IntegerPredicate());
	array.Filter(new IntegerPredicate()).Dump();
	
	int[] result1 = array.Filter(new IntegerPredicate()).Filter(new IntegerPredicate1());
	result1.Dump();

	string[] array2 = new string[] { "one", "two", "three", "four" };
	string[] result2 = array2.Filter(new StringPredicate());
	result2.Dump();

}

#region Interfaces&Implementations
public static bool IsTrue(int item) => item == 0;

public class StringPredicate : IPredicate<string>
{
	public bool IsMatch(string item) => item.Length >= 3;
}

public class IntegerPredicate : IPredicate<int>
{
	public bool IsMatch(int item) => item % 2 == 0;
}

public class IntegerPredicate1 : IPredicate<int>
{
	public bool IsMatch(int item) => item == 6;
}

public interface IPredicate<T>
{
	bool IsMatch(T item);
}
#endregion

public static class ArrayExtention
{
	public static T[] Filter<T>(this T[] array, IPredicate<T> predicate)
	{
		Validate(array, predicate);

		List<T> result = new List<T>();
		for (int i = 0; i < array.Length; i++)
		{
			if (predicate.IsMatch(array[i]))
			{
				result.Add(array[i]);
			}
		}

		return result.ToArray();
	}


	#region private
	private static void Validate<T>(T[] array, IPredicate<T> predicate)
	{
		if (array == null)
			throw new ArgumentNullException(nameof(array));
			
		if (predicate == null)
			throw new ArgumentNullException(nameof(predicate));
	}
	#endregion

}