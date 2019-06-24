class Solution(object):
    def largestValsFromLabels(self, values, labels, num_wanted, use_limit):
        """
        :type values: List[int]
        :type labels: List[int]
        :type num_wanted: int
        :type use_limit: int
        :rtype: int
        """
        res = 0
        value_to_labels = sorted(zip(values, labels))
        count = collections.Counter()
        for value, label in value_to_labels[::-1]:
            if num_wanted == 0: break
            if count[label] < use_limit:
                res += value
                count[label] += 1
                num_wanted -= 1
        return res
