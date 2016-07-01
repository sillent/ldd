#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <asm/current.h>
#include <linux/moduleparam.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dmitry Ulyanov");
MODULE_DESCRIPTION("First module");

/* EXPORT_SYMBOL_GPL("pcspkr"); */
/* MODULE_VERSION("0.1"); */

/* static char* name="world"; */
/* module_param(name, charp, S_IRUGO); */
/* MODULE_PARM_DESC(name, "Display in /var/log/kern.log"); */

static char *name="Dima";
static int count=1;
/* static int count2=2; */
/* static int array_count[]={count,count2}; */

static int  helloDima_init(void) {

        /* struct task_struct *current; */
        __u32 devsz=MKDEV(14,1);
        register_chrdev_region(devsz, 0, "myscull");
        printk(KERN_ALERT "The prio: %s, dev num: %u\n", current->parent->parent->parent->parent->comm, devsz);

        return 0;
}

static void  helloDima_exit(void) {
        printk(KERN_ALERT "EBB: Goodbye from the Dima LKM!\n");
}
module_param(name,charp,S_IRUGO);
module_param(count,int,S_IRUGO);
module_init(helloDima_init);
module_exit(helloDima_exit);
