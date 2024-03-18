class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points_sorted = []
        points_sorted = sorted(points, key=lambda x: x[0])
        num_arrows = 1
        
        prev_end = points[0][1]

        for ballon in points_sorted[1:]:
            #If not overlapping
            if(ballon[0] > prev_end):
                num_arrows+=1
                prev_end = ballon[1]
            else:
                prev_end = min(prev_end, ballon[1])
        
        return num_arrows