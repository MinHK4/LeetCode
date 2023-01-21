/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
    const answer = [];
    
    backtrack([], 1, s, answer);
    
    return answer;
};

function backtrack(dotIndexList, curDotIdx, s, answer){
    const parseIPList = parseValidIP(dotIndexList, s);
    if(parseIPList.length === 4){
        answer.push(parseIPList.join('.'));
        return;
    }
    
    if(dotIndexList.length >= 3) return;
    if(curDotIdx >= s.length) return;
    
    for(let i=curDotIdx; i<s.length; i++)
        backtrack([...dotIndexList, i], i+1, s, answer);
}

function parseValidIP(dotIndexList, s){
    if(dotIndexList.length === 3){
        const tempList= [0, ...dotIndexList, s.length];
        
        return tempList.reduce((acc, dot, idx) => {
            if(idx > 0){
                const str = s.substring(tempList[idx-1], tempList[idx]);
                if(str.length >= 2 && str[0] === '0') return acc;
                if(0 <= str/1 && str/1 <= 255) return [...acc, str/1]
            }
            
            return acc;
        }, [])
    }
    
    return [];
}

