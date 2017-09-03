// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {
  private Iterator<Integer> cur_iter;
  private Integer next;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
      cur_iter = iterator;
      if(cur_iter.hasNext())  next = cur_iter.next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
    return next;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
    Integer ret = next;
    next = cur_iter.hasNext() ? cur_iter.next() : null;
    return ret;
	}

	@Override
	public boolean hasNext() {
    return next != null;
	}
}
