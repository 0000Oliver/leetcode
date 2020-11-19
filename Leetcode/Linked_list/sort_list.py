class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def makeLinkedNode(numbers):
    dummy_head = ListNode(0)
    node = dummy_head
    for n in numbers:
        node.next = ListNode(n)
        node = node.next
    return dummy_head.next

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        slow,fast = head,head.next
        while fast and fast.next:
            fast,slow = fast.next.next,slow.next
        mid = slow.next
        slow.next=None
        left ,right = self.sortList(head),self.sortList(mid)
        h = res = ListNode(0)
        while left and right:
            if left.val<right.val:
                h.next = left
                left=left.next
            else:
                h.next = right
                right = right.next
            h = h.next

        h.next = left if left else right
        return res.next
    def sortList2(self, head: ListNode) -> ListNode:
        h = head
        length = 0
        intv = 1
        while h:
            h = h.next
            length = length+1
        res = ListNode(0)
        res.next = head
        while intv<length:
            pre = res
            h = res.next
            while h:
                h1 = h
                i = intv
                while i and h :
                    h = h.next
                    i = i-1
                if i:
                    break
                h2 = h
                i = intv
                while i and h :
                    h = h.next
                    i = i-1
                c1 = intv
                c2 = intv -i
                while c1 and c2:
                    if h1.val < h2.val:
                        pre.next  =h1
                        h1 = h1.next
                        c1 = c1-1
                    else:
                        pre.next = h2
                        h2 = h2.next
                        c2 = c2-1
                    pre =pre.next
                pre.next = h1 if c1 else h2
                while c1 >0 or c2>0:
                    pre = pre.next
                    c1 =c1-1
                    c2= c2-1
                pre.next = h
            intv *=2
        return res.next

if __name__ == "__main__":

    solution = Solution()
    numbers = [4,2,1,3]
    input_v = makeLinkedNode(numbers)
    solution.sortList(input_v)
