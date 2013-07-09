/*
 * One structure allocated per active
 * process. It contains all data needed
 * about the process while the
 * process may be swapped out.
 * Other per process data (user.h)
 * is swapped with the process.
 */
struct	proc
{
	char	p_stat;		/* 상태, NULL인 경우 해당하는 PROC[]를 비어있다고 여긴다. */
	char	p_flag;		/* 플래그 */
	char	p_pri;		/* 실행 우선순위, 값이 작을 수록 우선순위가 높다. */
	char	p_sig;		/* 수신된 시그날 */
	char	p_uid;		/* 사용자 ID (정수) */
	char	p_time;		/* 메모리나 스왑영역에 머물렀던 시간 (초) */
	char	p_cpu;		/* CPU를 사용한 누적 시간 (tick) */
	char	p_nice;		/* 디폴트는 0으로, nice시스템콜에 의해서 사용자가 값을 설정한다. */
	int	p_ttyp;		/* 프로세스를 조작하고 있는 단말 */
	int	p_pid;		/* 프로세스 ID */
	int	p_ppid;		/* 부모 프로세스 ID */
	int	p_addr;		/* 할당 받은 물리 메모리 어드레스 (64바이트 단위) */
	int	p_size;		/* 할당 받은 메모리 사이즈 (64바이트 단위) */
	int	p_wchan;	/* 슬립되고 있는 이유 */
	int	*p_textp;	/* 사용하고 있는 텍스트세그먼트 */
} proc[NPROC];

/* stat codes */
#define	SSLEEP	1		/* 잠자기, 실행 우선순위가 음수 값으로 슬립 중*/
#define	SWAIT	2		/* 잠자기, 실행 우선순위가 0이상 값으로 슬립 중*/
#define	SRUN	3		/* 실행 가능 상태 */
#define	SIDL	4		/* 프로세스 생성 처리 중 */
#define	SZOMB	5		/* 좀비 상태 */
#define	SSTOP	6		/* 트레이스에 따르는 개입을 기다림*/

/* flag codes */
#define	SLOAD	01		/* in core */
#define	SSYS	02		/* scheduling process */
#define	SLOCK	04		/* process cannot be swapped */
#define	SSWAP	010		/* process is being swapped out */
#define	STRC	020		/* process is being traced */
#define	SWTED	040		/* another tracing flag */
