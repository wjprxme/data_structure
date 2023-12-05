void shift(int k) {
	// TODO: Add your code here
	while (k < 0) {
		k+= mSize;
	}
	k %= mSize;
	auto itr = begin();
	while (k--) {
		itr++;
	}
	mHeader->next->prev=itr.ptr;
	
}