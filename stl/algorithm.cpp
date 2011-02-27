// begin-snippet finda
// parameter a
// parameter n
// parameter x
// parameter r
// parameter not_found
// parameter found
int r = find(a, a+n, x) - a;
if (r == n) {
    not_found
} else {
    found
}

// end-snippet

// begin-snippet find
// parameter v
// parameter x
// parameter r
// parameter not_found
// parameter found
int r = find(v.begin(), v.end(), x) - v.begin();
if (r == int(v.size())) {
    not_found
} else {
    found
}

// end-snippet


// begin-snippet findifa
// parameter a
// parameter n
// parameter pred
// parameter r
// parameter not_found
// parameter found
int r = find_if(a, a+n, pred) - a;
if (r == n) {
    not_found
} else {
    found
}

// end-snippet

// begin-snippet findif
// parameter v
// parameter pred
// parameter r
// parameter not_found
// parameter found
int r = find_if(v.begin(), v.end(), pred) - v.begin();
if (r == int(v.size())) {
    not_found
} else {
    found
}

// end-snippet


// begin-snippet fill
// parameter v
// parameter x
fill(v.begin(), v.end(), x);

// end-snippet

// begin-snippet filla
// parameter a
// parameter x
fill_n(a, (sizeof(a)/sizeof(a[0])), x);

// end-snippet

// begin-snippet unique
// parameter v
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// end-snippet

// begin-snippet uniquea
// parameter a
// parameter n
sort(a, a + n);
n = unique(a, a + n);

// end-snippet

// begin-snippet sort
// parameter v
sort(v.begin(), v.end());

// end-snippet

// begin-snippet sorta
// parameter a
// parameter n
sort(a, a + n);

// end-snippet

// begin-snippet partition
// parameter v
// parameter cnt
// parameter pred
int cnt = partition(v.begin(), v.end(), pred) - v.begin();

// end-snippet

// begin-snippet lower
// parameter v
// parameter x
// parameter not_found
// parameter found
int r = lower_bound(v.begin(), v.end(), x) - v.begin();
if (r == (int(v.size())) || v[r] != x) {
    not_found 
} else {
    found
}
// end-snippet

// begin-snippet lowera
// parameter a
// parameter n
// parameter x
// parameter not_found
// parameter found
int r = lower_bound(a, a + n, x) - a;
if (r == n || a[r] != x) {
    not_found 
} else {
    found
}
// end-snippet


// begin-snippet minimum
// parameter v
(*min_element(v.begin(), v.end()))
// end-snippet

// begin-snippet maximum
// parameter v
(*max_element(v.begin(), v.end()))
// end-snippet

// begin-snippet minimuma
// parameter a
// parameter n
(*min_element(a, a + n))
// end-snippet

// begin-snippet maximuma
// parameter a
// parameter n
(*max_element(a, a + n))
// end-snippet
//

// begin-snippet iota
// parameter v
// parameter i
iota(v.begin(), v.end(), i);
// end-snippet

// begin-snippet iotaa
// parameter a
// parameter n
// parameter i
iota(a, a + n, i);
// end-snippet

// begin-snippet sum
// parameter v
accumulate(v.begin(), v.end(), 0)
// end-snippet

// begin-snippet suma
// parameter a
// parameter n
accumulate(a, a + n, 0)
// end-snippet

// begin-snippet power
// parameter x
// parameter n
power(x, n)
// end-snippet