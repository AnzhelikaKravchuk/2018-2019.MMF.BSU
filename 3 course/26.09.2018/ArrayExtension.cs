using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataSetExtension
{
    public static class ArrayExtension
    {
        private const int LowerBase = 2;
        private const int UpperBase = 16;

        public static string[] TransformToString(int[] array, int @base)
        {
            if (array == null)
            {
                throw new ArgumentNullException(nameof(array));
            }

            if (@base < 2 || @base > 16)
            {
                throw  new ArgumentOutOfRangeException("TODO");
            }

            string[] result = new string[array.Length];

            for (int i = 0; i < array.Length; i++)
            {
                result[i] = TransformToString(array[i], @base);
            }

            return result;
        }

        public static void BubbleSort(int[] array)
        {
            if (array == null)
            {
                throw new ArgumentNullException(nameof(array));
            }

            //TODO
        }

        public static void MergeSort(int[] array)
        {
            if (array == null)
            {
                throw new ArgumentNullException(nameof(array));
            }

            //TODO
        }

        public static void QuickSort(int[] array)
        {
            if (array == null)
            {
                throw new ArgumentNullException(nameof(array));
            }

            QuickSort(array, 0, array.Length - 1);
        }

        private static void QuickSort(int[] array, int left, int right)
        {
            if (left < right)
            {
                int pivot = Partition(array, left, right);
                QuickSort(array, left, pivot - 1);
                QuickSort(array, pivot + 1, right);
            }
        }

        private static int Partition(int[] array, int low, int high)
        {
            int pivot = array[high];

            int i = low - 1;
            for (int j = low; j < high; j++)
            {
                if (array[j] <= pivot)
                {
                    i++;
                    Swap(ref array[i], ref array[j]);
                }
            }

            Swap(ref array[i + 1], ref array[high]);

            return i + 1;
        }

        private static void Swap<T>(ref T a, ref T b)
        {
            T temp = a;
            a = b;
            b = temp;
        }

        private static string TransformToString(int value, int @base)
        {
            string alphbet = "0123456789ABCDEF";

            //string result = string.Empty;

            var temp = new StringBuilder();

            while (value != 0)
            {
                int rest = value % @base;
                //result += alphbet[rest];
                temp.Append(alphbet[rest]);
                value /= @base;
            }

            char[] result = temp.ToString().ToCharArray();

            for (int i = 0; i < result.Length / 2 - 1; i++)
            {
                Swap(ref result[i], ref result[result.Length - i - 1]);
            }


            return result.ToString();
        }
    }
}
