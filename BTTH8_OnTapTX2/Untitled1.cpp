// boyer_moore_horsepool

void boyer_moore_hoorspool(string p, string t){
	int v = p.length(); int i = v - 1;
	while(i < t.length()){
		int k = v - 1;
		while(k > -1 && p[k] == t[i])
			i--; k--;
		if(k < 0)
			return true;
		else {
			int x = char_in_str(t[i],p);
			if(x < 0) i = i + v;
			else i = i + v - x - 1;
		}
	}
	return false;
}
