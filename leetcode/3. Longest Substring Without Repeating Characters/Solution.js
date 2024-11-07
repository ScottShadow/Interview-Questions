/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  let maxLength = 0;
  let start = 0;
  let currentSubstring = new Set();

  for (let end = 0; end < s.length; end++) {
    while (currentSubstring.has(s[end])) {
      currentSubstring.delete(s[start]);
      start++;
    }

    currentSubstring.add(s[end]);
    maxLength = Math.max(maxLength, end - start + 1);
  }

  return maxLength;
};
