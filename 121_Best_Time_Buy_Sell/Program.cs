using System;
using System.Linq;

namespace _121_Best_Time_Buy_Sell
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start...");
            int[] prices1 = {1,2,3,4,5};
            int[] prices2 = {3,3};
            
            var result = MaxProfit(prices1);
            Console.WriteLine(result);
            result = MaxProfit(prices2);
            Console.WriteLine(result);
        }

        public static int MaxProfit(int[] prices)
        {
            int minValue = prices.Min();
            int minIndex = prices.ToList().IndexOf(minValue);
            if (minIndex == prices.Length - 1)
            {
                return 0;
            }

            int maxValue = GetMaxValue(minValue, prices);

            return maxValue - minValue;
        }

        public static int GetMaxIndex(int start, int[] prices)
        {
            int maxValue = prices[start];
            int maxIndex = start;

            for (int i = start; i < prices.Length; i++)
            {
                
            }

            return maxIndex;
        }

        public static int GetMinIndex(int start, int[] prices)
        {
            int minValue = prices[start];
            int minIndex = start;

            for (int i = start; i < prices.Length; i++)
            {
                if (minValue > prices[i])
                {
                    minValue = prices[i];
                    minIndex = i;
                }
            }

            return minValue;
        }
    }
}
