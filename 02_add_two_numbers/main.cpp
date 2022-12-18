#include <iostream>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        int sum = convert(l1) + convert(l2);
        string str = to_string(sum);

        return insert(str);
    }

    void print(ListNode *l)
    {
        auto *x = l;
        while (x != nullptr)
        {
            cout << x->val << " ";
            x = x->next;
        }
        cout << endl;
    }

    int convert(ListNode *l)
    {
        int tmp = 0;
        int index = 1;
        auto *x = l;
        while (x != nullptr)
        {
            tmp += x->val * index;
            index *= 10;
            x = x->next;
        }

        return tmp;
    }

    ListNode *insert(string num)
    {
        ListNode *ret;
        ListNode *pointer = ret;

        int index = 1;

        for (auto i = num.length(); i >= 0; i--)
        {
            ListNode *x = new ListNode(toInt(num.at(i), index));
            index *= 10;
            pointer = x;
            pointer = pointer->next;
        }

        return ret;
    }

    int toInt(char c, int index)
    {
        return (c - '0') * index;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *list = new ListNode(2);
    list->next = new ListNode(4);
    list->next->next = new ListNode(3);

    ListNode *list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);

    Solution solution;
    solution.print(list);
    solution.print(list2);

    cout << solution.convert(list) << endl;
    cout << solution.convert(list2) << endl;

    return 0;
}