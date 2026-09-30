# Театр — объектная модель

## Классы

| Класс | Поля | Методы | Ассоциации |
|---|---|---|---|
| Role | 5 | 5 | — |
| Character | 4 | 3 | — |
| Scene | 5 | 4 | Character |
| Act | 4 | 1 | Scene |
| Audition | 3 | 1 | — |
| Costume | 5 | 2 | — |
| Decoration | 4 | 2 | Stage |
| Instrument | 5 | 4 | — |
| Violin | 2 | 2 | — |
| Cello | 2 | 2 | — |
| Piano | 2 | 2 | — |
| Flute | 2 | 2 | — |
| Contrabass | 2 | 2 | — |
| Equipment | 2 | 2 | — |
| Speaker | 3 | 2 | Hall |
| Microphone | 2 | 2 | — |
| Spotlight | 2 | 3 | — |
| Stage | 3 | 3 | — |
| Hall | 4 | 4 | Stage |
| DressingRoom | 4 | 3 | — |
| Buffet | 3 | 4 | — |
| Cast | 1 | 3 | — |
| Spectator | 7 | 4 | — |
| Worker | 4 | 5 | — |
| Director | 4 | 4 | Cast, Stage |
| Administrator | 3 | 5 | Violin |
| Accountant | 2 | 1 | — |
| HRManager | 2 | 1 | — |
| Composer | 2 | 1 | — |
| Playwright | 2 | 1 | — |
| Choreographer | 1 | 2 | — |
| SoundDesigner | 1 | 2 | — |
| Conductor | 3 | 2 | Instrument |
| Musician | 2 | 3 | — |
| Violinist | 1 | 1 | Violin |
| Cellist | 1 | 1 | Cello |
| Pianist | 1 | 1 | Piano |
| Flutist | 1 | 1 | Flute |
| Contrabassist | 1 | 1 | Contrabass |
| Actor | 5 | 4 | Role, Costume, Character |
| Singer | 2 | 2 | Microphone |
| OperaActor | 1 | 1 | Actor, Singer |
| Acrobat | 2 | 1 | — |
| Cashier | 1 | 1 | — |
| Cleaner | 1 | 3 | — |
| Doctor | 1 | 3 | — |
| Dancer | 3 | 2 | Costume |
| MakeupArtist | 1 | 2 | — |
| Bartender | 1 | 1 | — |
| Security | 1 | 2 | — |
| Playbill | 4 | 4 | — |
| PremiereInvitation | 1 | 1 | Playbill |
| Performance | 8 | 3 | Director, Hall, Cast |
| Rehearsal | 6 | 4 | Stage, Actor |
| Tour | 6 | 4 | Playbill |
| Schedule | 5 | 4 | — |
| Intermission | 4 | 3 | — |
| ReservedStage | 0 | 1 | Stage |
| Ticket | 4 | 3 | Spectator |
| Sponsor | 6 | 5 | Contract |
| Contract | 5 | 4 | Worker |
| Advertisement | 3 | 3 | — |
| Award | 6 | 3 | Worker |
| Warehouse | 4 | 3 | Costume |

## Наследование

| Тип | Пример |
|---|---|
| public | Worker → Actor, Instrument → Violin |
| protected | ReservedStage : protected Stage |
| private | PremiereInvitation : private Playbill |
| virtual public | Actor : virtual public Worker, Singer : virtual public Worker |
| множественное | OperaActor : public Actor, public Singer |
| ромбовидное | Worker ← (Actor, Singer) ← OperaActor |

## Разрешение имён через using

| Класс | Что открывает |
|---|---|
| PremiereInvitation | using Playbill::getPrice; using Playbill::announce; using Playbill::data; |
| ReservedStage | using Stage::rotate; |
| OperaActor | using Actor::perform; using Singer::singAria; |

## Исключения (12)

- InvalidAgeException
- EmptyNameException
- InvalidSalaryException
- InvalidTicketPriceException
- HallOverflowException
- WarehouseFullException
- InstrumentBrokenException
- BudgetExceededException
- ContractNotSignedException
- RoleNotLearnedException
- InvalidDateException
- TicketSoldOutException

## Итоговая статистика

| Показатель | Требование | Факт |
|---|---|---|
| Классов | ≥ 50 | 64 |
| Полей | ≥ 150 | ~170 |
| Поведений | ≥ 100 | ~145 |
| Ассоциаций | ≥ 30 | 30 |
| Исключений | ≥ 12 | 12 |
| Типов наследования | — | 6 |
| using-директив | — | 6 |