import scala.collection.mutable

class ListNode(var _x: Int = 0) {
    var next: ListNode = null
    var x: Int = _x
}

class CycleFinder {
    private val visited: mutable.Map[ListNode, Int] = mutable.Map()

    private def iterateOver(head: ListNode) : Unit = {
        if (head == null)
        {
            return
        }

        val visitCount = visited.get(head) match {
            case Some(value) => value + 1
            case None => 0
        }

        visited.addOne((head, visitCount))

        visited.get(head) match {
            case Some(value) => {
                if (value >= 2)
                {
                    return
                }
            }
            case None =>
        }
        hasCycle(head.next)
    }

    def hasCycle(head: ListNode): Boolean = {
        iterateOver(head)
        val sortedMap = visited.toSeq.sortBy(_._2).toMap
        println(sortedMap)

        false
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
    private val list3: ListNode = getTree3

    private def getTree3: ListNode = {
        var node1: ListNode = new ListNode(1)
        var node2: ListNode = new ListNode(2)
        var node3: ListNode = new ListNode(3)
        var node4: ListNode = new ListNode(4)

        node1.next = node2
        node2.next = node3
        node3.next = node4
        node4.next = node2

        node1
    }

    private def execute(list: ListNode): Unit = {
        val result = Solution.hasCycle(list)
        println("Result: " + result)
    }

    execute(list1)
    execute(list2)
    execute(list3)
}
