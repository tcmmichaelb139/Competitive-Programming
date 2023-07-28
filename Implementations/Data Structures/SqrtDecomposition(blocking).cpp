struct Sqrt {
	int blockSize;
	vector<long long> vals;
	vector<long long> blocks;

	Sqrt(int sqrtn, vector<long long> &v) : blockSize(sqrtn), blocks(sqrtn, 0) {
		vals = v;
		for (int i = 0; i < size(vals); i++) {
			blocks[i / blockSize] += vals[i];
		}
	}

	void upd(int p, long long v) {
		blocks[p / blockSize] -= vals[p];
		vals[p] = v;
		blocks[p / blockSize] += vals[p];
	}

	long long query(int r) {
		long long res = 0;
		for (int i = 0; i < r / blockSize; i++) res += blocks[i];
		for (int i = (r / blockSize) * blockSize; i <= r; i++) res += vals[i];
		return res;
	}

	long long query(int l, int r) { return query(r) - query(l - 1); }
};
