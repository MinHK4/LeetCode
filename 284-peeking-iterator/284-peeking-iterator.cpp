/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return Iterator(*this).next();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
    
    /*부모 클래스의 메소드 그대로 활용하기 때문에 코드 추가 X
	int next() {
	}
	bool hasNext() const {
	}
    */

};

/*
Iterator 개념보다는 클래스 상속 개념이 더 중요한 문제
*/