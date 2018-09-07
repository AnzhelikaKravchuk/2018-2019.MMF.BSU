<Query Kind="Program">
  <Namespace>System.Data.Entity</Namespace>
  <Namespace>System.Threading.Tasks</Namespace>
</Query>

void Main()
{
	var binaryInit = 0b1010_1011_1100_1101_1110_1111_0000_1111_0000_1010_1111_1111_1111_1111_1111;
	string binaryString = Convert.ToString(binaryInit, 2);
	var binaryNoration = new Notation(2);
	binaryNoration.Dump();
	binaryNoration.Alphabet.Dump("Alphabet(2)");
	binaryString.ToDecimalConverter(binaryNoration).Dump();

	var hexInit = 0xAB_CD_EF;
	hexInit.Dump("Number:");
	string hexString = "ABCDEF";
	var hexNoration = new Notation(16);
	hexNoration.Dump();
	hexNoration.Alphabet.Dump("Alphabet(16)");

	hexString.ToDecimalConverter(hexNoration).Dump();

	//test
	"".Dump("Test");
	int test = 456675;
	test.Dump();
	string binaryTest = Convert.ToString(test, 16).ToUpper();
	binaryTest.Dump();
	binaryTest.ToDecimalConverter(hexNoration).Dump();
}

public static class StringExtention
{
	public static long ToDecimalConverter(this string source, Notation notation)
	{
		if (string.IsNullOrEmpty(source))
		{
			throw new ArgumentException($"The string {nameof(source)} can not be null or empty!");
		}

		if (notation == null)
		{
			throw new ArgumentNullException($"The object {nameof(notation)} can not be null!");
		}

		long number = 0, product = 1;

		int @base = notation.Base;

		string alphabet = notation.Alphabet;

		string upperString = source.ToUpper();

		for (int i = source.Length - 1; i >= 0; i--)
		{
			// tracking OwerflowException!
			checked
			{
				if (ConvertToValue(upperString[i], alphabet) == -1)
				{
					throw new ArgumentException($"Invalid symbol {source[i]} in string!");
				}
				else
				{
					number += product * ConvertToValue(upperString[i], alphabet);

					product *= @base;
				}
			}
		}

		return number;
	}

	private static int ConvertToValue(char symbol, string alphbet) => alphbet.IndexOf(symbol);
}

public sealed class Notation // sealed no descendants!
{
	#region Constants

	private const int UpperValue = 16;
	private const int LowerValue = 2;

	#endregion

	#region Fields

	private int @base;

	#endregion

	#region Constructors

	public Notation()
		: this(10)
	{
	}

	public Notation(int @base)
	{
		this.Base = @base;
		this.Alphabet = this.StringCreation();
	}

	#endregion

	#region Properties

	public int Base
	{
		get => this.@base;

		set // or private set ?
		{
			if (value < LowerValue || value > UpperValue)
			{
				throw new ArgumentOutOfRangeException($"Base of Notation must be more or equal then {LowerValue} and less or equal then {UpperValue}!");
			}

			this.@base = value;
			this.Alphabet = this.StringCreation(); // remove if set private
		}
	}

	public string Alphabet { get; private set; }

	#endregion

	#region Private Methods

	private string StringCreation()
	{
		int @base = this.Base;

		StringBuilder sb = new StringBuilder(@base);

		int symbol = 'A';

		for (int i = 0; i < @base; i++)
		{
			if (i <= 9)
			{
				sb.Append(i);
			}
			else
			{
				sb.Append((char)symbol++); // casting to char important
			}
		}

		return sb.ToString();
	}

	#endregion
}