#ifndef HUMAN_VS_MEDIUM_MACHINE_H_INCLUDED
#define HUMAN_VS_MEDIUM_MACHINE_H_INCLUDED
struct Position *lookAhead(int n, char turn, struct Board *current, int lookAheadLevel);
int PlayHumanVsMediumMachine(int LookAheadLevel);
void HumanVsMediumMachine(int LookAheadLevel);

#endif // HUMAN_VS_MEDIUM_MACHINE_H_INCLUDED
