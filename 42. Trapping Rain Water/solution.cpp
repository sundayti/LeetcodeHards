class Solution {
public:
  int trap(vector<int>& height) {
    int m = 0;
    int ind = 0;
    for (size_t i = 0; i < height.size(); ++i) {
      if (height[i] >= m) {
        m = height[i];
        ind = i;
      }
    }

    int current_max = 0;
    int ans = 0;
    for (size_t i = 0; i < ind; ++i) {
      if (height[i] < current_max) {
        ans += current_max - height[i];
      } else {
        current_max = height[i];
      }
    }

    current_max = 0;
    for (size_t i = height.size() - 1; i > ind; --i) {
      if (height[i] < current_max) {
        ans += current_max - height[i];
      } else {
        current_max = height[i];
      }
    }

    return ans;
  }
};