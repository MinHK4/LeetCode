/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var findSubsequences = function(nums) {
    const answer = [];
    limit = nums.length;
    
    recursive(nums, 0, [], limit, answer);

    return answer;
};

function recursive(nums, curIdx, curList, limit, answer){
    if(curIdx === limit){
        if(curList.length >= 2 && isListNonDecreasing(curList) && !isListRepeated(answer, curList))
            answer.push(curList);
        return;
    }
    
    recursive(nums, curIdx+1, [...curList, nums[curIdx]], limit, answer);
    recursive(nums, curIdx+1, curList, limit, answer);
}
    
function isListNonDecreasing(list){
    let flag = true;
    
    list.forEach((el, idx) => {
        if(idx > 0 && list[idx-1] > el){
            flag = false
            return;
        }
    })
    
    return flag;
}

function isListRepeated(srcList, targetList){
    return srcList.some(list => isSameList(list, targetList));
}

function isSameList(list1, list2) {
    if (list1.length === list2.length) {
        return list1.every((el, idx) => {
            if (el === list2[idx]) {
                return true;
            }
            return false;
        });
    }
    
    return false;
}

/*
Brute Force 풀이로 접근해야 할 것 같음
일단 배열의 길이가 최대 15라서 크기가 작음
2^15 경우의 수만 다 확인해주면 되서 문제 없을 것 같음

그냥 모든 부분 집합을 다 만들게 재귀로 짜서 돌리고
맨 마지막에 asnwer에 넣기 전에 크기랑 non-decreasing 조건 확인하기

++
같은 숫자로 조합이 중복되는 경우 예외처리가 필요함
*/