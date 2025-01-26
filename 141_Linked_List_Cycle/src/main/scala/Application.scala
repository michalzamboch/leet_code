import scala.collection.mutable

class ListNode(var _x: Int = 0) {
    var next: ListNode = null
    var x: Int = _x
}

class CycleFinder {
    private val visited: mutable.HashSet[ListNode] = mutable.HashSet()
    private var cycleFound: Boolean = false

    private def iterateOver(head: ListNode) : Unit = {
        if (head == null)
        {
            return
        }

        if (!visited.contains(head))
        {
            visited.add(head)
            hasCycle(head.next)
        }
        else
        {
            cycleFound = true
        }
    }

    def hasCycle(head: ListNode): Boolean = {
        iterateOver(head)
        cycleFound
    }
}

object Solution {
    def hasCycle(head: ListNode): Boolean = {
        new CycleFinder().hasCycle(head)
    }
}

object Application extends App {
    private val list1: ListNode = null
    private val list2: ListNode = new ListNode(1) { next = new ListNode(2) }

    private def execute(list: ListNode): Unit = {
        val result = Solution.hasCycle(list)
        println("Result: " + result)
    }

    execute(list1)
    execute(list2)
}
