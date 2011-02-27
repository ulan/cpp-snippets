// begin-snippet pthread_create
// parameter id
// parameter attr
// parameter start
// parameter arg
int failed = pthread_create(&id, &attr, start, &arg);
// end-snippet

// begin-snippet pthread_exit
// parameter result
int failed = pthread_exit(&result);
// end-snippet

// begin-snippet pthread_detach
// parameter id
int failed = pthread_detach(id);
// end-snippet

// begin-snippet pthread_self
int id = pthread_self();
// end-snippet

// begin-snippet pthread_equal
// parameter id1
// parameter id2
int equal = pthread_equal(id1, id2);
// end-snippet


// begin-snippet pthread_join
// parameter id
// parameter result
int failed = pthread_join(id, &result);
// end-snippet

// begin-snippet pthread_cancel
// parameter id
int failed = pthread_cancel(id);
// end-snippet

