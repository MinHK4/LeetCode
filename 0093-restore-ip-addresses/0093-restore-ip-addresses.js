/**
* @param {string} s
* @return {string[]}
*/
var restoreIpAddresses = function(s) {
    var firstRun = [{
        current: "",
        remaining: s
    }];
    
    return recursivelyGetIps(firstRun, []);
};

var recursivelyGetIps = function(trialList, successfulIps = []) {
    var newTrialList = [];
        
    for (var i = 0; i < trialList.length; i++) {
        var thisTrial = trialList[i];
        var { current, remaining } = thisTrial;
        
        var ipSectionsSoFar = current.split(".").length;
        
        var remainingPieceIsValidFullIp = ipSectionsSoFar === 4
        && !hasLeadingZeros(remaining) 
        && !isOverTheLimit(remaining);
        
        
        var stillHasSectionsLeft = ipSectionsSoFar < 4
        
        if (remainingPieceIsValidFullIp) {
            successfulIps.push(current + remaining);
        } else if (remaining && stillHasSectionsLeft) {
            var j = 0;
            var newStr = "";
        
            while (j <= 2 && remaining[j]) {
                newStr += remaining[j];
                var remainingFromHere = remaining.substring(j+1, remaining.length);
                
                var validToAddToTrial = newStr 
                && !hasLeadingZeros(newStr) 
                && !isOverTheLimit(newStr)
                && remainingFromHere
                && remainingFromHere.length <= getMaxLengthForRemStr(current + newStr, remainingFromHere);
                
                if (validToAddToTrial) {                    
                    newTrialList.push({
                        current: current + newStr + ".",
                        remaining: remainingFromHere
                    });
                }
                
                j++;
            }
        }
    }
    
    if (newTrialList.length) {
        return recursivelyGetIps(newTrialList, successfulIps)
    } else {
        return successfulIps;
    }
}

var getMaxLengthForRemStr = function(ipAddressSoFar, remStr) {
    var sectionsLeft = 4 - ipAddressSoFar.split(".").length;
    var maxDigitsPerSection = 3;
    
    return sectionsLeft * maxDigitsPerSection;
}

var hasLeadingZeros = function(ipSection) {
    return ipSection[0] === "0" && ipSection.length > 1;
}

var isOverTheLimit = function(ipSection) {
    return Number(ipSection) > 255;
}