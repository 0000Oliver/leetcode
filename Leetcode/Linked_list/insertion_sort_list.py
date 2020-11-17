import sys
import time
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def evaluate(self):
        for fun in dir(self)[-2:]:
            input_v = ListNode(4)
            input_v.next = ListNode(2)
            input_v.next.next = ListNode(1)
            input_v.next.next.next = ListNode(3)




            startime = time.time()
            f = getattr(Solution,fun)
            result = f(self,input_v)
            while result:
                print(result.val)
                result = result.next
            endtime = time.time()
            print("方法",fun,'耗时',(endtime-startime)*1000000000000000000)

    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head :
            return head
        m = sys.maxsize
        dmmuy_head = ListNode(-m)
        dmmuy_head.next = head
        node = head.next
        dmmuy_head.next.next = None
        while node:
            next_node = node.next
            tmp = dmmuy_head
            while tmp:
                if tmp.next==None:
                    tmp.next = node
                    node.next = None
                    break
                elif node.val < tmp.next.val:
                    node.next = tmp.next
                    tmp.next = node
                    break
                tmp = tmp.next
            node = next_node

        return dmmuy_head.next
    def insertionSortList2(self, head: ListNode) -> ListNode:
        if not head :
            return head
        m = sys.maxsize
        dmmuy_head = ListNode(-m)
        dmmuy_head.next = head
        node = head.next
        prev = head
        while node:
            if node.val <prev.val:
                tmp = dmmuy_head
                while tmp.next.val < node.val:
                    tmp = tmp.next
                prev.next = node.next
                node.next =tmp.next
                tmp.next = node
                node = prev.next
            else:
                prev = prev.next
                node = node.next

        return dmmuy_head.next

if __name__ == "__main__":



    solution = Solution()
    solution.evaluate()
