import heapq

class SeatManager:

    def __init__(self, n: int):
        self.seat = []
        for i in range(n):
            self.seat.append(i+1)

    def reserve(self) -> int:
        n = heapq.heappop(self.seat)
        return n

    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.seat,seatNumber)
        



# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)