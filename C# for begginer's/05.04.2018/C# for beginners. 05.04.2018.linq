<Query Kind="Program">
  <Namespace>System.Data.Entity</Namespace>
</Query>

void Main()
{
	int[] array = { 1, 2, 77, 7, 701 };

	List<int> expected = new List<int> { 77, 7, 701 };

	int[] actual = array.Filter(new DigitPredicate(7));

	actual.Dump();

	array = new int[] { 1, 2, -77, 7, -701 };

	expected = new List<int> { -77, 7, -701 };

	actual = array.Filter(new DigitPredicate(7));

	actual.Dump();

	string[] emails = {
						"anzhelika.kravchuk@gmail.com",
						"anzhelika_kravchukepam.com",
						"anzhelika_kravchuk@epam.com",
						"anzhelika_kravchukgmail",
						"anzhelika_kravchuk.gmail@"
					   };

	string[] actualMails = emails.Filter(predicate);
	actualMails.Dump();
}

#region Extention methods
public static class ArrayExtentionRefactor
{
	public static T[] Filter<T>(this T[] source, IPredicate<T> predicate)
	{
		if (source == null)
		{
			throw new ArgumentNullException(nameof(source));
		}

		var list = new List<T>();

		for (int i = 0; i < source.Length; i++)
		{
			if (predicate.IsMatch(source[i]))
			{
				list.Add(source[i]);
			}
		}

		return list.ToArray();
	}
}
#endregion

#region Interfaces
public interface IPredicate<T>
{
	bool IsMatch(T item);
}
#endregion

#region Classes-predicates
public class DigitPredicate : IPredicate<int>
{
	private int digit;
	public DigitPredicate(int digit)
	{
		Digit = digit;
	}

	public int Digit
	{
		get => digit;
		set
		{
			if (value < 0 || value > 9)
			{
				throw new ArgumentOutOfRangeException($"{nameof(value)} is not digit!");
			}

			digit = value;
		}
	}

	public bool IsMatch(int number)
	{
		number = Math.Abs(number);

		while (number != 0)
		{
			int t = number % 10;

			if (t == this.digit)
			{
				return true;
			}

			number /= 10;
		}

		return false;
	}
}

public class StringPredicate : IPredicate<string>
{
	private Regex stringPattern;

	public StringPredicate(string stringPattern)
	{
		this.stringPattern = new Regex(stringPattern);
	}

	public bool IsMatch(string item) => stringPattern.IsMatch(item);
}

#endregion