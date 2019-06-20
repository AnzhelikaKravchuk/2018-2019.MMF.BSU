using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 20.06.2019
{
    static class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(CreateFace());

            Console.WriteLine(127.ToBinary());

            Console.WriteLine(127.To(16));

            Console.WriteLine(127.To(2));

            Console.WriteLine(127.To(8));
        }

        public static string CreateFace()
        {
            var builder = new StringBuilder();

            builder.Append("\n +\"\"\"\"\"+");
            builder.Append("\n(| o o |)");
            builder.Append("\n |  ^  |");
            builder.Append("\n | '-' |");
            builder.Append("\n +-----+");

            return builder.ToString();
        }

        public static string ToBinary(this int value)
        {
            var builder = new StringBuilder();

            char sign = value >= 0 ? ' ' : '-';

            value = Math.Abs(value);

            while (value != 0)
            {
                char unit = value % 2 == 0 ? '0' : '1';

                builder.Append(unit);

                value /= 2;
            }

            builder.Append(sign);

            for (int i = 0; i < builder.Length / 2; i++)
            {
                char tmp = builder[i];

                builder[i] = builder[builder.Length - i - 1];

                builder[builder.Length - i - 1] = tmp;
            }

            return builder.ToString();
        }

        public static string To(this int value, int @base)
        {
            var builder = new StringBuilder();

            string alphabet = "0123456789ABCDEF";

            char sign = value >= 0 ? ' ' : '-';

            value = Math.Abs(value);

            while (value != 0)
            {
                int rest = value % @base;

                builder.Append(alphabet[rest]);

                value /= @base;
            }

            builder.Append(sign);

            for (int i = 0; i < builder.Length / 2; i++)
            {
                char tmp = builder[i];

                builder[i] = builder[builder.Length - i - 1];

                builder[builder.Length - i - 1] = tmp;
            }

            return builder.ToString();
        }
    }
}


