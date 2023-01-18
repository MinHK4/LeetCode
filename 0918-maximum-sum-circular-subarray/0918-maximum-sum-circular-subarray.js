/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubarraySumCircular = function(nums) {
    
    let totalSum = 0;
    let tempMin = Number.MAX_SAFE_INTEGER, minSum = Number.MAX_SAFE_INTEGER;
    let tempMax = Number.MIN_SAFE_INTEGER, maxSum = Number.MIN_SAFE_INTEGER;
    
    nums.forEach(num => {
        totalSum += num;
        
        tempMin = Math.min(num, tempMin + num);
        tempMax = Math.max(num, tempMax + num);
        
        minSum = Math.min(minSum, tempMin);
        maxSum = Math.max(maxSum, tempMax);
    });
    
    return maxSum > 0 ? Math.max(maxSum, totalSum - minSum) : maxSum;
}

// Kadane 알고리즘을 이용해서 부분합의 최대 최소를 구하고
// Circular한 경우를 다 고려해주기 위해서 부분합의 최대, 전체합에서 부분합의 최소를 뺀 값을 비교한다
// 끝 인덱스를 감싸는 경우에 대해서 max가 감싸고 있으면 min을 찾아서 빼서 얻어줄 수 있고
// 끝 인덱스를 감싸는 경우에 대해서 min 감싸고 있으면 max를 찾아서 얻어줄 수 있음
// 다만 배열의 모든 값이 음수인 경우에 가장 큰 원소 하나만의 값만 하면 되므로 예외 처리를 해줘야 함
