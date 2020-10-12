// checkbook.cpp  -- The function definitions of the class template for the Checkbooktemplate <class DataType>Checkbook<DataType>::Checkbook( ){}template <class DataType>Checkbook<DataType>::Checkbook( float initBalance ){	balance = initBalance;}template <class DataType>void Checkbook<DataType>::setBalance( float amount ){	balance = amount;}template <class DataType>bool Checkbook<DataType>::writeCheck( const DataType & amount ){	if ( amount > balance )		return false;	balance -= amount;	lastCheck = amount;	return true;}template <class DataType>void Checkbook<DataType>::deposit( float amount ){	balance += amount;	lastDeposit = amount;}template <class DataType>float Checkbook<DataType>::getBalance( ) const {	return balance;}template <class DataType>DataType Checkbook<DataType>::getLastCheck( ) const{	return lastCheck;}template <class DataType>float Checkbook<DataType>::getLastDeposit( ) const{	return lastDeposit;}