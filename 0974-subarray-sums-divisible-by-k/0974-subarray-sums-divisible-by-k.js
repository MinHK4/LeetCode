/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function(nums, k) {
    
    const count = new Array(k).fill(0);
    count[0]++;
    
    let ans = 0;
    let remainder = 0;
    nums.forEach(num => {
        remainder = (remainder + num % k + k) % k;
        ans += count[remainder];
        count[remainder]++;
    })
    
    return ans;
};

// prefix sum을 이용해서 prefix sum의 remainder 값이 같으면 그 두 인덱스 사이의 부분집합이
// divisible한 부분집합이라는 것을 알 수 있음
// 예외로 나눠떨어지는 경우는 항상 자기 자신만 있는 집합의 경우도 포함해줘야 함
// 매번 remainder 값을 구해서 이전에 자신과 같은 remainder 값을 가진 개수를 더해주면서 쌓아주면 됨