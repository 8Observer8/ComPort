#include "Sender.h"

Sender::Sender( const QString &portName,
                QSerialPort::BaudRate baudRate,
                QSerialPort::DataBits dataBits,
                QSerialPort::Parity parity,
                QSerialPort::StopBits stopBits,
                QSerialPort::FlowControl flowControl ) :
    m_port( portName ),
    m_baudRate( baudRate ),
    m_dataBits( dataBits ),
    m_parity( parity ),
    m_stopBits( stopBits ),
    m_flowControl( flowControl )
{
    // Set the port name
    m_port.setPortName( m_portName );

    // Open the port
    if ( !m_port.open( QIODevice::WriteOnly ) ) {
        throw PortError( m_port.errorString().toStdString() );
    }

    m_port.setBaudRate( m_baudRate );
    m_port.setDataBits( m_dataBits );
    m_port.setParity( m_parity );
    m_port.setStopBits( m_stopBits );
    m_port.setFlowControl( m_flowControl );
}

Sender::~Sender()
{
    m_port.close();
}

void Sender::send( const QByteArray &data ) throw( PortError )
{
    if ( !m_port.isOpen() ) {
        throw PortError( m_port.errorString().toStdString() );
    }

    // Write data to the port
    if ( m_port.write( data ) == -1 ) {
        throw PortError( m_port.errorString().toStdString() );
    }
}
