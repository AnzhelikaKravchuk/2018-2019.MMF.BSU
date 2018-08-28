<Query Kind="Program">
  <Namespace>System.Data.Entity</Namespace>
</Query>

void Main()
{
	List<int> array = new List<int>() { 1, 2, 77, 7, 24, 68, 701 };
	var result = array.Filter(x => x % 2 == 0);
	array.Add(22);
	array.Add(101);
	foreach (var element in result)
	{
		element.Dump();
	}

	List<int> array1 = new List<int>() { 1, 2, 77, 7, 24, 68, 701 };
	var result1 = array1.Where(x => x % 2 == 0);
	array1.Add(22);
	array1.Add(101);
	foreach (var element in result1)
	{
		element.Dump();
	}

	//	array = new int[] { 1, 22, 68, 2, -77, 7, -701 };
	//
	//	expected = new List<int> { -77, 7, -701 };
	//
	//	//actual = array.Filter(new DigitPredicate(7));
	//
	//	actual.Dump();
	//
	//	actual = array.Filter(x => x % 2 == 0);
	//
	//	actual.Dump();
	//	#endregion
	//
	//	#region Filter with array of string
	//
	//	string[] emails = {
	//						"anzhelika.kravchuk@gmail.com",
	//						"anzhelika_kravchukepam.com",
	//						"anzhelika_kravchuk@epam.com",
	//						"anzhelika_kravchukgmail",
	//						"anzhelika_kravchuk.gmail@"
	//					   };
	//
	//	string pattern = @"([a-zA-Z0-9_\-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([a-zA-Z0-9\-]+\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})";
	//
	//	Regex regex = new Regex(pattern);
	//	//	var list = new List<string>();
	//	//	for (int i = 0; i < emails.Length; i++)
	//	//	{
	//	//		if (regex.IsMatch(emails[i]))
	//	//		{
	//	//			list.Add(emails[i]);
	//	//		}
	//	//	}
	//
	//	//string[] result = emails.Filter(new StringPredicate(pattern));
	//	result.Dump();
	//
	//	result = emails.Filter(regex.IsMatch);
	//	result.Dump();
	//
	//	result = emails.Filter(s => s.Length > 23);
	//	result.Dump();
	//
	//	#endregion
	//
	//	new DigitPredicate(7).IsMatch(237).Dump();
	//
	//	//Predicate<int> predicate = new Predicate<int>(new DigitPredicate(7).IsMatch);
	//	DigitPredicate predicated = new DigitPredicate(7);
	//	Predicate<int> predicate = predicated.IsMatch;
	//	predicate = null;//IsEven;
	//					 //predicate?.Invoke(237).Dump();
	//	if (predicate != null)
	//	{
	//		predicate(237);//<=>predicate.Invoke(237);
	//	}

}

public static class ArrayExtentionRefactor
{
	public static IEnumerable<T> Filter<T>(this IEnumerable<T> source, Func<T, bool> predicate)
	{
		if (source == null)
		{
			throw new ArgumentNullException(nameof(source));
		}

		if (predicate == null)
		{
			throw new ArgumentNullException(nameof(predicate));
		}

		return  FilterInner<T>(source, predicate);
	}

	private static IEnumerable<T> FilterInner<T>(this IEnumerable<T> source, Func<T, bool> predicate)
	{
		foreach (var element in source)
		{
			if (predicate(element))
				yield return element;
		}
	}
}
