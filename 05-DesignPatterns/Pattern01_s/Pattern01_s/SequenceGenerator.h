

#ifndef SEQUENCEGENERATOR_H
#define SEQUENCEGENERATOR_H 

class SequenceGenerator{

private:
	static SequenceGenerator *pgen;
	int n;
	
	SequenceGenerator(int n=0);
	SequenceGenerator(const SequenceGenerator& gen);
	SequenceGenerator& operator=(const SequenceGenerator&);
	
public:
	virtual ~SequenceGenerator();
	static SequenceGenerator* getInstance();
	int getNombre() ;
};

#endif
