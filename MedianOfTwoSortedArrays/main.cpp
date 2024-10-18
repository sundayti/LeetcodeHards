#include <vector>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    size_t i = 0;
    size_t j = 0;
    int n = nums1.size() + nums2.size();
    bool isEven = (n % 2 == 0);
    n = n / 2;

    double current = 0;
    int previous = 0;

    for (size_t k = 0; k <= n; ++k) {
      previous = current;

      if (i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j])) {
        current = nums1[i];
        ++i;
      } else {
        current = nums2[j];
        ++j;
      }
    }

    if (isEven) {
      return (current + previous) / 2.0;
    }
    return current;
  }
};
