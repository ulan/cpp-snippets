// begin-snippet vi
// parameter int
vector<int>
// end-snippet

// begin-snippet vvi
// parameter int
vector< vector<int> >
// end-snippet

// begin-snippet vvvi
// parameter int
vector< vector< vector<int> > >
// end-snippet

// begin-snippet pb
// parameter x
push_back(x)
// end-snippet

// begin-snippet pair
// parameter int
pair<int, int>
// end-snippet

// begin-snippet mp
// parameter x
// parameter y
make_pair(x, y)
// end-snippet

// begin-snippet range
// parameter v
v.begin(), v.end()
// end-snippet

// begin-snippet sz
// parameter x
(int(x.size()))
// end-snippet

// begin-snippet foreach
// parameter v
// parameter it
// parameter body
for (typeof(v.begin()) t = v.begin(); it != v.end(); ++it) {
   body 
}
// end-snippet


// begin-snippet cout
// parameter x
cout << x << endl;
// end-snippet

// begin-snippet sep
// parameter x
" " << x
// end-snippet

// begin-snippet couta
// parameter a
// parameter n
if (debug) {
    if (n > 0) cout << a[0]; 
    for (int i = 1; i < n; ++i) cout << " " << a[i]; 
    cout << endl;
}

// end-snippet

// begin-snippet coutv
// parameter v
if (debug) {
    string prefix;
    for (typeof(v.begin()) it = v.begin(); it != v.end(); ++it) {
        cout << prefix << *it;
        prefix = " ";
    }
    cout << endl;
}

// end-snippet
