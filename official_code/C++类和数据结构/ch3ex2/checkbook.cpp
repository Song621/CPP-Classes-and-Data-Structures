// checkbook.cpp  -- The function definitions of the class template for the Checkbooktemplate <class DataType>Checkbook<DataType>::Checkbook( ){	lastIndex = -1;	numChecks = 0;}template <class DataType>Checkbook<DataType>::Checkbook( float initBalance ){	balance = initBalance;	lastIndex = -1;	numChecks = 0;}template <class DataType>void Checkbook<DataType>::setBalance( float amount ){	balance = amount;}template <class DataType>bool Checkbook<DataType>::writeCheck( const DataType & amount ){	if ( amount > balance )		return false;	balance -= amount;	lastIndex++;	if ( lastIndex == CAPACITY )		lastIndex = 0;	lastChecks[ lastIndex ] = amount;	if ( numChecks != CAPACITY )		numChecks++;	return true;}template <class DataType>void Checkbook<DataType>::deposit( float amount ){	balance += amount;	lastDeposit = amount;}template <class DataType>float Checkbook<DataType>::getBalance( ) const {	return balance;}template <class DataType>DataType Checkbook<DataType>::getLastCheck( ) const{	return lastChecks[ lastIndex ];}// getLastChecks returns up to CAPACITY checks// checks in the info.checks array are stored in order with the latest check first// info.numChecks is the number of checks that are returnedtemplate <class DataType>CheckInfo<DataType> Checkbook<DataType>::getLastChecks(  ) const{	CheckInfo<DataType> info;	info.numChecks = numChecks;	for ( int i = 0, j = lastIndex; i < numChecks; i++, j-- ) {		if ( j == -1 )			j = CAPACITY - 1;		info.checks[ i ] = lastChecks[ j ];	}	return info;}template <class DataType>float Checkbook<DataType>::getLastDeposit( ) const{	return lastDeposit;}