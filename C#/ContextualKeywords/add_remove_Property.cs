using System;

public delegate void Notify();  // delegate
                    
public class ProcessBusinessLogic
{
    public event Notify ProcessCompleted;
    
    public event Notify ProcessCompletedProperty
    {
        //add => ProcessCompleted += value;
        //remove => ProcessCompleted -= value;
        add
        {
            Console.WriteLine("prop += value;");
            ProcessCompleted += value;
        }
        remove
        {
            Console.WriteLine("prop -= value;");
            ProcessCompleted -= value;
        }
    }// event

    public void StartProcess()
    {
        Console.WriteLine("Process Started!");
        // some code here..
        OnProcessCompleted();
    }

    protected virtual void OnProcessCompleted() //protected virtual method
    {
        //if ProcessCompleted is not null then call delegate
        ProcessCompleted?.Invoke(); 
    }
}
class Program
{
    public static void Main()
    {
        ProcessBusinessLogic bl = new ProcessBusinessLogic();
        bl.ProcessCompletedProperty += bl_ProcessCompleted; // register with an event
        //b1.ProcessCompleted?.Invoke(); // error CS0103: The name 'b1' does not exist in the current context
        bl.StartProcess();
    }

    // event handler
    public static void bl_ProcessCompleted()
    {
        Console.WriteLine("Process Completed!");
    }
}

/*
OUTPUT:

Process Started!
Process Completed!
*/